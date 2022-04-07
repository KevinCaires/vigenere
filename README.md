## Trabalho de estrutura de dados


### Objetivo
    Criar um programa que execute a criptografia e descriptografia de vigenere.


## Implementação
    O programa foi implementado no formato de argumentos, então deve-se fazer conforme a tabela de comandos abaixo:

    OBS: Os argumentos ignoram strings após espaços em branco.

| Argumento | Descrição |
|-----------|-----------|
| --text    | Texto de entrada para criptografar ou descriptografar. |
| --key     | Chave a ser usada para criptografar ou descriptografar. |
| --encode  | Argumento que indica criptografia do texto. |
| --decode  | Argumento que indica descriptografia do texto. |


    Exemplo de criptografia:
        ./vigenere --text umtextoqualquer --key minhasuperchave --encode
    Exemplo de descriptografia:
        ./vigenere --text guglxlifyrnxuzv --key minhasuperchave --decode
