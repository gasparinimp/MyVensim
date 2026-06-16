/**
 * @file handleBody.h
 * @brief Template do idioma Handle-Body, tambem conhecido como Bridge.
 *
 * O Handle funciona como a casca publica do objeto. O Body guarda os dados
 * reais e controla quantos Handles apontam para ele por meio de contagem de
 * referencias.
 */

#ifndef HANDLE_BODY_H
#define HANDLE_BODY_H

/**
 * @class Handle
 * @brief Classe template que representa a parte publica do idioma Handle-Body.
 *
 * @tparam T Tipo do Body associado ao Handle.
 *
 * A classe Handle guarda um ponteiro para um objeto Body e delega para ele a
 * responsabilidade de armazenar os dados. Copias de Handle passam a compartilhar
 * o mesmo Body, aumentando o contador de referencias.
 */
template <class T>
class Handle {
protected:
    T* pImpl; /*!< Ponteiro para o Body que contem a implementacao real. */

public:
    /**
     * @brief Construtor padrao. Cria um Body vazio e o associa ao Handle.
     */
    Handle() {
        pImpl = new T();
        pImpl->attach();
    }

    /**
     * @brief Construtor que recebe um Body ja criado.
     * @param body Ponteiro para o Body que sera controlado pelo Handle.
     */
    Handle(T* body) {
        pImpl = body;
        pImpl->attach();
    }

    /**
     * @brief Destrutor. Reduz a contagem de referencias do Body.
     */
    virtual ~Handle() {
        pImpl->detach();
    }

    /**
     * @brief Construtor de copia. Faz dois Handles compartilharem o mesmo Body.
     * @param other Handle que sera copiado.
     */
    Handle(const Handle& other) {
        pImpl = other.pImpl;
        pImpl->attach();
    }

    /**
     * @brief Operador de atribuicao. Troca o Body atual pelo Body de outro Handle.
     * @param other Handle usado como origem da atribuicao.
     * @return Referencia para o proprio Handle.
     */
    Handle& operator=(const Handle& other) {
        if (this != &other) {
            other.pImpl->attach();
            pImpl->detach();
            pImpl = other.pImpl;
        }
        return *this;
    }
};

/**
 * @class Body
 * @brief Classe base para os corpos das implementacoes concretas.
 *
 * Cada Body possui um contador de referencias. Quando nao existe mais nenhum
 * Handle apontando para ele, o proprio Body se destroi.
 */
class Body {
private:
    int refCount; /*!< Quantidade de Handles apontando para este Body. */

    Body(const Body&);
    Body& operator=(const Body&);

public:
    /**
     * @brief Construtor padrao. Inicia o Body sem nenhum Handle associado.
     */
    Body() : refCount(0) {}

    /**
     * @brief Aumenta a contagem de referencias.
     */
    void attach() {
        refCount++;
    }

    /**
     * @brief Diminui a contagem de referencias e apaga o Body se ela chegar a zero.
     */
    void detach() {
        refCount--;
        if (refCount == 0) {
            delete this;
        }
    }

    /**
     * @brief Retorna a contagem atual de referencias.
     * @return Numero de Handles apontando para este Body.
     */
    int getRefCount() const {
        return refCount;
    }

    /**
     * @brief Destrutor virtual para permitir destruicao correta por heranca.
     */
    virtual ~Body() {}
};

#endif
