#include <iostream>
#include <cstring> 

#define VELOCIDADE_DA_LUZ 300000000

class TagIndividuo
{
private:

    unsigned long long Distancia;
    char  *TagInd;

public:

    TagIndividuo();
    ~TagIndividuo();

    unsigned long long getDistanciaIndividuo();
    void SetDistanciaIndividuo(unsigned long long ValorCalculado);
    
    const char* GetTagInd() const;
    void SetTagInd(const char* NovaTag);


    unsigned long long CalculoDistanciaInd(unsigned int TempoRetornado);
};

TagIndividuo::TagIndividuo(/* args */)
        : Distancia(0), TagInd(nullptr)
   {
   }

TagIndividuo::~TagIndividuo()
   {
       delete[] TagInd;
   }

unsigned long long TagIndividuo::getDistanciaIndividuo() 
   {
   
       return Distancia;
   }
   
void TagIndividuo::SetDistanciaIndividuo(unsigned long long ValorCalculado)
   {
     
       Distancia = ValorCalculado;    
   }

const char* TagIndividuo::GetTagInd() const
   {
  
       return TagInd;
   }

void TagIndividuo::SetTagInd(const char*  NovaTag)
   {
       delete[] TagInd;
       TagInd = new char[strlen(NovaTag) + 1];
       strcpy(TagInd, NovaTag);   

   }

unsigned long long TagIndividuo::CalculoDistanciaInd(unsigned int TempoRetornado)
   {
       unsigned long long Espaco = static_cast<unsigned long long>(TempoRetornado) * VELOCIDADE_DA_LUZ;

       SetDistanciaIndividuo(Espaco);

       return Espaco;
   }