#pragma once
#include <translatable.h>
#include <labels.h>
#include <marker_classes.h>
#include <instruction.h>
#include <binop.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <interference_graph.h>


namespace L2{

        class Interference_Graph;

        // Mr. Soustrup, you make me sad.
        class IG_Node;

        using nodes_set_t = std::map<std::string, compiler_ptr<IG_Node>>;
        using neighbor_set_t = std::set<compiler_ptr<IG_Node>,
                                                     Interference_Graph::Node_Ptr_Cmp>;
        using adjacency_set_t = std::map<std::string,
                                         neighbor_set_t>;


        class Function : public virtual AST_Item{
                // This is an awful mess...
        public:
                Function();
                Function(L2_Target_Label name, int64_t args, int64_t locals);
                Function(Function&& rhs) = default;

                //// Needs to be here because it needs access to instruction context
                std::vector<Inst_Posn> find_successors(Inst_Posn);

                //// Register Allocation
                void populate_liveness_sets();
                Interference_Graph make_interference_graph();
                compiler_ptr<Function> allocate_registers();


                //// Spill utilities
                std::string find_prefix();
                std::string get_prefix();
                std::vector<compiler_ptr<Instruction>> spill_these(std::vector<compiler_ptr<IG_Node>>);
                void insert_spill_accesses(
                        std::vector<compiler_ptr<Instruction>>::iterator pos,
                        const std::string &id_to_spill,
                        const std::unordered_map<std::string, std::string> &spill_map,
                        std::vector<compiler_ptr<Instruction>> & new_instrs);

                //// Translation utilities
                liveness_sets_t make_liveness_sets();
                void dump(std::ostream &out) const override;


                void accept(AST_Item_Visitor &v) override;

                //// Data
                int64_t stack_args() const;
                int64_t stack_shift() const;

                void expand_stack(std::ostream&out) const;
                void shrink_stack(std::ostream&out) const;

                L2_Target_Label name;
                int64_t arguments;
                int64_t locals;

                std::unordered_map<std::string, int64_t> spill_offset_table;

                std::vector<compiler_ptr<Instruction>> instructions;


        private:
                static char rando_chardrissian();
                int prefix_counter;
                boost::optional<std::string> prefix;
        };
}