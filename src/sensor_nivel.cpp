#include "sensor_nivel.hpp"

#include <iomanip>
#include <sstream>
#include <utility>

namespace {
std::string formatarValor(double valor) {
    std::ostringstream saida;
    saida << std::setprecision(12) << valor;
    return saida.str();
}
}

SensorNivel::SensorNivel(std::string tagInicial, double valorInicial, std::string unidadeInicial)
    : _tag(std::move(tagInicial)),
      _valor(valorInicial),
      _unidade(std::move(unidadeInicial)),
      _ativo(false),
      _totalLeituras(0) {
}

std::string SensorNivel::tag() const {
    return _tag;
}

double SensorNivel::valor() const {
    return _valor;
}

std::string SensorNivel::unidade() const {
    return _unidade;
}

bool SensorNivel::estaAtivo() const {
    return _ativo;
}

void SensorNivel::ativar() {
    _ativo = true;
}

void SensorNivel::desativar() {
    _ativo = false;
}

bool SensorNivel::registrarLeitura(double novoValor) {
    if (!_ativo) {
        return false;
    }

    if (novoValor < 0 || novoValor > 100) {
        return false;
    }

    _valor = novoValor;
    _totalLeituras++;

    return true;
}

int SensorNivel::totalLeituras() const {
    return _totalLeituras;
}

std::string SensorNivel::resumo() const {
    const std::string sufixo = _unidade.empty() ? "" : " " + _unidade;
    const std::string estado = _ativo ? "ativo" : "inativo";

    return _tag + ": " + formatarValor(_valor) + sufixo +
           " | " + estado +
           " | leituras: " + std::to_string(_totalLeituras);
}