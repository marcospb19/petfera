# Exportador

Utilize esse utilitário para exportar tabelas filtradas do registro de \
animais gerado pelo petfera

## Compilação

Utilize o Makefile para compilar dentro da pasta src/

## Uso

O programa exportar procura pelo arquivo animais.txt no mesmo diretório que \
você está ao rodar o comando

Escreva `./exportar \<Nome-Do-Arquivo\>`

Para exportar animais.txt para o \<Nome-Do-Arquivo\>

### Flags disponíveis:
> -c \<Classe\>

*Filtra animais pela classe animal.*

> -v \<veterinario\>

*Filtra animais sob a responsabilidade apenas do veterinário determinado.*

> -t \<tratador\>

*Filtra animais sob a responsabilidade apenas do tratador determinado.*
