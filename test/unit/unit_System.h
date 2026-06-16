#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

/**
 * @class UnitSystem
 * @brief Classe que agrupa os testes unitarios da classe SystemImpl.
 */
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

    /**
     * @brief Testa o uso do idioma Handle-Body em SystemImpl.
     *
     * O teste verifica se dois handles passam a compartilhar o mesmo Body apos
     * a atribuicao, se o contador de referencias e atualizado e se a
     * autoatribuicao nao altera o objeto.
     */
    static void unit_System_HandleBody(void);
};

/**
 * @brief Executa todos os testes unitarios de SystemImpl.
 */
void run_unit_tests_System(void);

#endif
