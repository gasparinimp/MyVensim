#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

// Assinaturas dos testes unitários para cada método de Model
class UnitModel
{
public:
    static void unit_Model_constructor(void);
    static void unit_Model_ParameterizedConstructor();
    static void unit_Model_CopyConstructor();
    static void unit_Model_Operator();
    static void unit_Model_destructor(void);
    static void unit_Model_getName(void);
    static void unit_Model_setName(void);
    static void unit_Model_criaSistema(void);
    static void unit_Model_criaFluxo(void);
    static void unit_Model_run(void);
};

    // Assinatura da função que vai rodar todos os testes de Model
    void run_unit_tests_Model(void);

#endif