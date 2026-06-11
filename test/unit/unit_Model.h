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
    static void unit_Model_addSystem();
    static void unit_Model_addFlow();
    static void unit_Model_createModel();
    static void unit_Model_createSystem();
    static void unit_Model_createFlow();
    static void unit_Model_deleteModel();
    static void unit_Model_deleteSystem();
    static void unit_Model_deleteFlow();
    static void unit_Model_run();
};

    // Assinatura da função que vai rodar todos os testes de Model
    void run_unit_tests_Model(void);

#endif