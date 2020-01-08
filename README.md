# OBR-2020
Robô para a OBR de 2020


## Resgate

Para a identificação das vitimas estamos utilizando a biblioteca de visão computacional OpenCV com técnicas de segmentação por borda.


Este é o métodopara a identificação das vitimas, que retorna uma tupla contendo o par ordenado da posição do centro do circulo e a magnitude do raio.
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

Valor do acumulador de th

- _minR_:

Valor mínimo de busca do raio do círculo.

- _maxR_:

Valor máximo de busca do raio do círculo.