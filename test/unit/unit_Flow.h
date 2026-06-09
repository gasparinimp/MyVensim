#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

class UnitFlow {
// Assinaturas dos testes unitarios para cada metodo de Flow
public:
    static void unit_Flow_constructor(void);
    static void unit_Flow_ParameterizedConstructor();
    static void unit_Flow_CopyConstructor();
    static void unit_Flow_Operator();
    static void unit_Flow_destructor(void);
    static void unit_Flow_getName(void);
    static void unit_Flow_setName(void);
    static void unit_Flow_getSource(void);
    static void unit_Flow_setSource(void);
    static void unit_Flow_getTarget(void);
    static void unit_Flow_setTarget(void);
    static void unit_Flow_execute(void);
};

// Assinatura da funcao que vai rodar todos os testes de Flow
void run_unit_tests_Flow(void);

#endif