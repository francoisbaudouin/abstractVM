/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Type
*/

#ifndef TYPE_HPP_
#define TYPE_HPP_

#include "AOperand.hpp"

namespace AbstractVM {

    template <typename T>
    class Int8 : public AOperand {
        public:
            Int8();
            ~Int8();

        protected:
        private:
        eOperandType _Type;
        T _data;
    };

    template <typename T>
    class Int16 : public AOperand {
        public:
            Int16();
            ~Int16();

        protected:
        private:
        eOperandType _Type;
        T _data;
    };

    template <typename T>
    class Int32 : public AOperand {
        public:
            Int32();
            ~Int32();

        protected:
        private:
        eOperandType _Type;
        T _data;
    };

    template <typename T>
    class Float : public AOperand {
        public:
            Float();
            ~Float();

        protected:
        private:
        eOperandType _Type;
        T _data;
    };

    template <typename T>
    class Double : public AOperand {
        public:
            Double();
            ~Double();

        protected:
        private:
        eOperandType _Type;
        T _data;
    };

    template <typename T>
    class BigDecimal : public AOperand {
        public:
            BigDecimal();
            ~BigDecimal();

        protected:
        private:
        eOperandType _Type;
        T _data;
    };

}

#endif /* !TYPE_HPP_ */
