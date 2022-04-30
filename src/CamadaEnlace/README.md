# Camada de Enlace
Na camada de enlace, fazemos 2 processos: o enquadramento e o controle de erro. Dentre os algoritmos de controle de erro, temos os de detecção de erro e os de correção de erro.

## Controle de erro
### CRC
O algoritmo CRC serve para detecção de erros e é baseado em divisões polinomiais. Os dados são considerados um polinômio dividendo e é definido (com um "acordo entre cavalheiros") qual será o polinômio divisor. 

Para efetuar a divisão polinomial com os números binários, utiliza-se a divisão módulo 2.

No lado transmissor, o processo é realizado da seguinte maneira:
1. Se o polinômio divisor é de n-bits, os dados são primeiramente "expandidos" com n-1 zeros ao final
2. É realizada a operação XOR entre o dividendo e o divisor de modo que seus MSB sejam "encaixados".
3. Atualiza-se o dividendo com o resultado da operação 2
4. Desloca-se o divisor um bit para a direita com relação ao dividendo
5. Repetir os passos 2 a 4 até que o dividendo original (sem os últimos n-1 zeros que foram adicionados passo 1) se torne 0
6. Os n-1 zeros que havíamos adicionado no início da operação (que não necessariamente continuam sendo zeros) são o resto da divisão, e consistem no código CRC
7. Concatena-se os dados originais com os n-1 bits do resto para gerar o dado final a ser transmitido  
![CRC - Transmissão](/resources/crc-example-transmit.jpeg)

No lado receptor, o processo é realizado da seguinte maneira:
1. Os dados recebidos consistem dos dados originais do transmissor concatenados com o resto da divisão realizada pelo transmissor
2. Efetua-se o mesmo processo feito no transmissor, porém sem a necessidade de expandir os dados.
3. No final do processo, o resto da divisão deve ser 0.  
![CRC - Recepção](/resources/crc-example-receive.jpeg)

#### CRC 32
Para a nossa implementação, o algoritmo do CRC 32 será simplesmente o algoritmo descrito para o CRC utilizando o polinõmio de 32 bits

![CRC32 - Polinômio](/resources/crc32-poly.jpeg)

Cuja representação binária em haxadecimal é 0x04C11DB7 no modo "normal" e 0xEDB88320 no modo "reverso". Utilizaremos o modo "normal".

# Referências
- [CRC - Explicação](https://info.support.huawei.com/info-finder/encyclopedia/en/CRC.html)
- [CRC - Tabelas com dados e explicações](https://en.wikipedia.org/wiki/Cyclic_redundancy_check)
- [CRC32 - Explicação e otimizações](https://commandlinefanatic.com/cgi-bin/showarticle.cgi?article=art008)