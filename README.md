# CG-with-OpenGL

## Como rodar
### Para rodar em ambientes com distribuição Mac
Rodar `sudo apt-get install freeglut3-dev`

### Para rodar em ambientes com distribuição Mac
Rodar `brew install mesa-glu && brew install freeglut`<br>
Instalar [XQuartz](https://www.xquartz.org/), necessário para interação gráfica.<br>

### Após configurar o ambiente
Com o ambiente configurado, bastar rodar `make compile`.<br>
Um binário com nome `exe.out` será gerado na raiz do projeto.<br>
Então, basta executá-lo: `./exe.out`<br>

## To do list:
Proposta da parte avaliativa de CG:

Desenvolver um ambiente virtual utilizando-se da OpenGL contendo geometrias que façam referência à FURG e/ou ao C3, tais como logos, instalações prediais, laboratórios, etc. É fundamental que a(s) geometria(s) seja(m) algo que corresponda(m) aos nossos espaços. Preferencialmente, a implementação deve ser realizada em ANSI C ou C++, mas vocês podem implementar em outras linguagens de programação caso desejarem;

O código deve conter (vide pesos):
- [ ] (25%) Modelagem das geometrias (ambiente a ser reproduzido);
- [x] (20%) Funções para translação, rotação e escala implementadas com as matrizes necessárias para serem aplicadas no ambiente utilizando-se da glMultMatrix();
- [x] (15%) Funções para as projeções perspectiva e ortogonal implementadas com as matrizes necessárias para serem aplicadas no ambiente utilizando-se da glMultMatrix();
- [x] (15%) Aplicação do modelo de iluminação (Phong) e de tonalização (Gouraud) estudados (podem utilizar as rotinas disponíveis na OpenGL);
- [ ] (15%) Implementar e aplicar em alguma parte do ambiente ao menos um dos algoritmos de rasterização (Digital Differential Analyzer - DDA ou Bresenham);
    - [x] Implementação DDA;
    - [ ] Implementação Bresenham;
    - [ ] Aplicação dos algoritmos;
- [ ] (10%) Aplicação de um dos algoritmos de visibilidade estudados (podem utilizar as rotinas disponíveis na OpenGL).

## Issues:
- Atualmente, o algoritmo de Bresenham só funciona para delta y positivo e menor que delta x, é necessário modificar isso;
- Como lidar com o eixo z nos algoritmos de rasterização?
- De que forma temos que aplicar esss algoritmos?
