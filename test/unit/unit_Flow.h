#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

// Assinaturas dos testes unitarios para cada metodo de Flow
void unit_Flow_constructor(void);
void unit_Flow_destructor(void);
void unit_Flow_getName(void);
void unit_Flow_setName(void);
void unit_Flow_getSource(void);
void unit_Flow_setSource(void);
void unit_Flow_getTarget(void);
void unit_Flow_setTarget(void);
void unit_Flow_execute(void);

// Assinatura da funcao que vai rodar todos os testes de Flow
void run_unit_tests_Flow(void);

#endif