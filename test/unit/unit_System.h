#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

class UnitSystem {
public:
// Assinaturas dos testes unitarios para cada metodo de System
    static void unit_System_constructor(void);
    static void unit_System_destructor(void);
    static void unit_System_ParameterizedConstructor();
    static void unit_System_CopyConstructor();
    static void unit_System_Operator();
    static void unit_System_getName(void);
    static void unit_System_setName(void);
    static void unit_System_getValue(void);
    static void unit_System_setValue(void);
};

// Assinatura da funcao que vai rodar todos os testes do System
void run_unit_tests_System(void);

#endif