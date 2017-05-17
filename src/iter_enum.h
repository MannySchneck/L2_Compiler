#include<type_traits>

template<typename E>
constexpr typename std::underlying_type<E>::type toUType(E enum_val){
        return static_cast<typename std::underlying_type<E>::type>(enum_val);
}

template<typename T>
class Enum{
public:
        class Iterator {
        public:
                Iterator(T val) :
                        cur_value(toUType(val)){}

                T operator*(){
                        return static_cast<T>(cur_value);
                }

                void operator++(){
                        ++cur_value;
                }

                bool operator !=(const Iterator &rhs){
                        return cur_value != rhs.cur_value;
                }
        private:
                typename std::underlying_type<T>::type cur_value;
        };
};

template<typename T>
typename Enum<T>::Iterator begin(Enum<T>){
        return typename Enum<T>::Iterator{T::begin};
}

template<typename T>
typename Enum<T>::Iterator end(Enum<T>){
        return typename Enum<T>::Iterator{T::end};
}
