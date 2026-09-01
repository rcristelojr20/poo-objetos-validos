class SensorNivel:
    def __init__(self, tag: str, valor: float, unidade: str = ""):
        self._tag = tag
        self._valor = valor
        self._unidade = unidade
        self._ativo = False
        self._total_leituras = 0

    @property
    def tag(self):
        return self._tag

    @property
    def valor(self):
        return self._valor

    @property
    def unidade(self):
        return self._unidade

    @property
    def ativo(self):
        return self._ativo

    @property
    def total_leituras(self):
        return self._total_leituras

    def ativar(self):
        self._ativo = True

    def desativar(self):
        self._ativo = False

    def registrar_leitura(self, novo_valor):
        if not self._ativo:
            return False

        if novo_valor < 0 or novo_valor > 100:
            return False

        self._valor = novo_valor
        self._total_leituras += 1

        return True

    def resumo(self) -> str:
        sufixo = f" {self._unidade}" if self._unidade else ""
        estado = "ativo" if self._ativo else "inativo"

        return f"{self._tag}: {self._valor:g}{sufixo} | {estado} | leituras: {self._total_leituras}"