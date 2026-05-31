#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

// Assinaturas dos testes unitários para cada método de Model
void unit_Model_constructor(void);
void unit_Model_destructor(void);
void unit_Model_getName(void);
void unit_Model_setName(void);
void unit_Model_criaSistema(void);
void unit_Model_criaFluxo(void);
void unit_Model_run(void);

// Assinatura da função que vai rodar todos os testes de Model
void run_unit_tests_Model(void);

#endif