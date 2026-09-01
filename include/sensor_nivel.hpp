#ifndef SENSOR_NIVEL_HPP
#define SENSOR_NIVEL_HPP

#include <string>

class SensorNivel {
private:
    std::string _tag;
    double _valor;
    std::string _unidade;
    bool _ativo;
    int _totalLeituras;

public:
    SensorNivel(std::string tagInicial, double valorInicial, std::string unidadeInicial = "");

    std::string tag() const;
    double valor() const;
    std::string unidade() const;

    bool estaAtivo() const;
    void ativar();
    void desativar();

    bool registrarLeitura(double novoValor);
    int totalLeituras() const;

    std::string resumo() const;
};

#endif