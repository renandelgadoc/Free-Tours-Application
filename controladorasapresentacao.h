#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <string.h>
#include <ncurses.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"


//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras e implementa��es de m�todos.

class CntrApresentacaoControle{
    private:
        Email email;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoPessoal *cntrApresentacaoPessoal;
        IApresentacaoExcursoes *cntrApresentacaoExcursoes;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoPessoal(IApresentacaoPessoal*);
        void setCntrApresentacaoExcursoes(IApresentacaoExcursoes*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPessoal(IApresentacaoPessoal *cntr){
            cntrApresentacaoPessoal = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoExcursoes(IApresentacaoExcursoes *cntr){
    cntrApresentacaoExcursoes = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
    public:
        bool autenticar(Email*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoPessoal:public IApresentacaoPessoal{
    private:
        IServicoPessoal *cntrServicoPessoal;
        IServicoExcursoes *cntrServicoExcursoes;
        void consultarDadosPessoais();
    public:
        void executar(Email);
        void cadastrar();
        void setCntrServicoPessoal(IServicoPessoal*);
        void setCntrServicoExcursoes(IServicoExcursoes*);
};

inline void CntrApresentacaoPessoal::setCntrServicoPessoal(IServicoPessoal *cntr){
    cntrServicoPessoal = cntr;
}

inline void CntrApresentacaoPessoal::setCntrServicoExcursoes(IServicoExcursoes *cntr){
    cntrServicoExcursoes = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoExcursoes: public IApresentacaoExcursoes{
    private:
        IServicoExcursoes *cntr;
        void cadastrarExcursao();
        void descadastrarExcursao();
        void consultarExcursao();
        void cadastrarAvaliacao() ;
        void descadastrarAvaliacao() ;
        void cadastrarSessao() ;
        void descadastrarSessao() ;
    public:
        void executar();
        void executar(Email);
        void setCntrServicoExcursoes(IServicoExcursoes*);
};

inline void CntrApresentacaoExcursoes::setCntrServicoExcursoes(IServicoExcursoes *cntr){
    this->cntr = cntr;
}


#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED