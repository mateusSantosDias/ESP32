#include <iostream>
#include <cstring> 

#define VELOCIDADE_DA_LUZ 300000000

class TagMaquina
{
private:

    unsigned long long Distancia;
    char *TagMaq;

public:

    TagMaquina(/* args */);
    ~TagMaquina();

    unsigned long long getDistanciaMaquina();
    void SetDistanciaMaquina(unsigned long long ValorCalculado);
    
    const char* GetTagMaquina() const;
    void SetTagMaquina(const char* NovaTag);


    unsigned long long CalculoDistanciaMaquina(unsigned int TempoRetornado);
};

TagMaquina::TagMaquina(/* args */)

      : Distancia(0), TagMaq(nullptr)
   {
   }

TagMaquina::~TagMaquina()
   {
       delete[] TagMaq;
   }

unsigned long long TagMaquina::getDistanciaMaquina() 
   {
   
       return Distancia;
   }
   
void TagMaquina::SetDistanciaMaquina(unsigned long long ValorCalculado)
   {
     
       Distancia = ValorCalculado;    
   }

const char* TagMaquina::GetTagMaquina() const
   {
  
       return TagMaq;
   }

void TagMaquina::SetTagMaquina(const char*  NovaTag)
   {
       delete[] TagMaq;
       TagMaq = new char[strlen(NovaTag) + 1];
       strcpy(TagMaq, NovaTag);   

   }

unsigned long long TagMaquina::CalculoDistanciaMaquina(unsigned int TempoRetornado)
   {
       unsigned long long Espaco = static_cast<unsigned long long>(TempoRetornado) * VELOCIDADE_DA_LUZ;

       SetDistanciaMaquina(Espaco);

       return Espaco;
   }