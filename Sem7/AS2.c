#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

enum reg_t
{
    A = 0,
    B,
    C,
    D,
    RLAST
};

enum opcode_t
{
    MOVI = 0,
    ADD = 8,
    SUB = 9,
    MUL = 10,
    DIV = 11,
    IN,
    OUT,
    OPLAST
};

union operand_t
{
    struct
    {
        int rd, rs;
    } ops;
    int rop;
    int imm;
};

struct instr_t
{
    enum opcode_t opcode;
    union operand_t opnd;
};

struct reg_state_t
{
    unsigned char data;
    unsigned char init;
    // ???
};

enum opcode_t arith_opcode(unsigned Data)
{
    return Data >> 4;
}

int print_reg(unsigned Data)
{
    switch (Data)
    {
    case A:
        printf("A");
        return 0;
    case B:
        printf("B");
        return 0;
    case C:
        printf("C");
        return 0;
    case D:
        printf("D");
        return 0;
    default:
        return 1;
    }
}

int decode(unsigned Data)
{
    // movi
    if (((Data >> 7) & 0x1) == 0)
    {

        printf("MOVI %d\n", Data);
        return 0;
    }
    // inout
    if (((Data >> 6) & 0x1) == 1)
    {
        int res = 0;

        switch ((Data >> 2) & 0x3f)
        {
        case 0x30:
            printf("IN ");
            break;
        case 0x31:
            printf("OUT ");
            break;
        default:
            return 1;
        }

        res = print_reg(Data & 0x3);
        if (res != 0)
            return 1;
        printf("\n");

        return 0;
    }
    else
    {
        switch ((Data >> 4) & 0xf)
        {
        case ADD:
            printf("ADD ");
            break;
        case SUB:
            printf("SUB ");
            break;
        case MUL:
            printf("MUL ");
            break;
        case DIV:
            printf("DIV ");
            break;
        default:

            return 1;
        }

        print_reg((Data >> 2) & 0x3);
        printf(", ");
        print_reg(Data & 0x3);
        printf("\n");

        return 0;
    }
}

int main()
{
    unsigned Data;
    while (scanf(" %x ", &Data) == 1)
    {
        if (decode(Data) != 0)
        {
            printf("ERROR \n");
            break;
        }
    }

    return 0;
}