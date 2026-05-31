#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

// Assinaturas dos testes unitarios para cada metodo de System
void unit_System_constructor(void);
void unit_System_destructor(void);
void unit_System_getName(void);
void unit_System_setName(void);
void unit_System_getValue(void);
void unit_System_setValue(void);

// Assinatura da funcao que vai rodar todos os testes do System
void run_unit_tests_System(void);

#endif