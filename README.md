# Jogo

## Descrição

Isa é ligeiramente competitiva e está jogando com seu amigo, Bruno, um jogo de tabuleiro. Esse jogo possui regras e uma maneira de jogar bem diferente. Bruno ir´a colocar peças em algumas posições e Isa deve decidir em quais posições irá colocar as suas peças. Mas, ela só pode colocar uma peça em uma posição que não contenha uma quantidade ímpar de vizinhos com peças do adversário.

Sabendo de suas habilidades de programação, ela pede sua ajuda para determinar todas as posições em que ela pode colocar uma peça. Uma peça é dita vizinha a outra se tiver um lado compartilhado com essa, ou seja, se estiver acima, abaixo ou ao lado dessa peça. Você nunca pode colocar uma peça na mesma posição da peça do adversário.

Observação: Para esse exercício você deve implementar no mínimo duas funções, sendo uma delas uma função responsável por ”marcar” as posições em que podemos colocar uma peça e outra a sua escolha. Além disso, você deve utilizar alocação dinâmica para a matriz.

## Input

Na primeira linha serão dados dois inteiros N e M, sendo, respectivamente, o número de linhas e colunas. Logo após será dado um grid com N linhas e M colunas, composto por carácteres. Uma posi¸c˜ao no grid (i, j) contém uma peça de Bruno se estiver marcada com o caracter ”X”. Já uma posição livre é marcada pelo caracter ”.”

## Output

Como saída você deve retornar a matriz com as peças de Bruno marcadas com ”X” e as posições em que Isa pode colocar uma peça marcadas com ”*”. Já as posições em que Isa não pode colocar uma peça basta manter o carácter que estava na leitura. Para esse exercício você deve utilizar funções, matrizes e alocação dinâmica.
