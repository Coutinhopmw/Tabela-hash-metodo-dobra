import random

# Função para gerar chaves numéricas
def gerar_chaves(quantidade, valor_maximo):
    return random.sample(range(valor_maximo + 1), quantidade)

# Gerando 1000 chaves numéricas entre 0 e 1000
chaves = gerar_chaves(1000, 1000)

# Salvando as chaves no arquivo .txt
with open("chaves.txt", "w") as arquivo:
    for chave in chaves:
        arquivo.write(f"{chave}\n")

print("Chaves geradas e salvas em chaves.txt com sucesso!")
