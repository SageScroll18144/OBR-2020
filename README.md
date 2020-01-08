# OBR-2020
Robô para a OBR de 2020


## Estrutura

A estrutura do robô pode ser encontrada no link a seguir: https://www.tinkercad.com/things/atXvg4NdNgS-cool-stantia-wolt

## Componentes eletrônicos

## Código

O código está sendo escrito em duas linguagens. Python3(Resgate) e C++(Seguidor de Linha e Desvio de Obstáculo)

### Resgate

#### Vitimas
Para a identificação das vitimas estamos utilizando a biblioteca de visão computacional OpenCV com técnicas de segmentação por borda.

Este é o método para a identificação das vitimas, que retorna uma tupla contendo o par ordenado da posição do centro do circulo e a magnitude do raio.
```python
circle(img, dp, minDist, param_1, param_2, minR, maxR)
```
- _img_:

A imagem que será feita a leitura dos circulos

- _dp_:

Parâmetro que vota se a imagem apresenta ou não um circulo.

- _minDist_:

Valor mínimo para a distância entre os circulos

- _param_1_:

Valor passado na borda Canny.
```python
cv2.Canny(img, param_1, param_1/2)
```
- _param_2_: 

Valor do acumulador de threshold

- _minR_:

Valor mínimo de busca do raio do círculo.

- _maxR_:

Valor máximo de busca do raio do círculo.

#### Parede

Com o objetivo de evitar a colisão entre o robô e a parede está sendo usado quatro sensores ultrassônicos. O código faz a varredura do valor dos sensores e se atingir o valor de corte é enviado um aviso para o robô, para que ele pare o atual movimento.

#### Triângulo

A ideia inicial é similar a detecção de vitimas, porém vamos procurar um retângulo.

#### Garra

Ainda em desenvolvimento

#### Repositório
No último estágio do robô temos um "Guarda vitimas". No final as vitimas são descartadas na área de Resgate.

### Seguidor de Linha

### Desvio de Obstáculo

