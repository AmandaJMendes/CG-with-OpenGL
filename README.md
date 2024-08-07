# CG-with-OpenGL

## Como rodar
### Para rodar em ambientes com distribuição Linux
Rodar `sudo apt-get install freeglut3-dev`

### Para rodar em ambientes com distribuição Mac
Rodar `brew install mesa-glu && brew install freeglut`<br>
Instalar [XQuartz](https://www.xquartz.org/), necessário para interação gráfica.<br>

> [!NOTE]  
> Para os ambientes Linux e Mac, o comando `make compile` pode ser utilzado. Para Windows, seguir a documentação.

#

### Para rodar no Windows
Métodos retirados de [Open GL (freeGLUT) install in Windows With Visual Studio Code](https://github.com/zamansheikh/OpenGLWithVsCodeWin-Linux)
Após seguir o processo de instalação e configuração acima basta rodar:
`g++ main.cpp -o main -lopengl32 -lfreeglut -lglu32 -lglew32 -lglfw3 -lgdi32 -lmingw32` para compilar o programa<br>
`./main.exe` para abrir o programa<br>

## To do list:
Proposta da parte avaliativa de CG:

Desenvolver um ambiente virtual utilizando-se da OpenGL contendo geometrias que façam referência à FURG e/ou ao C3, tais como logos, instalações prediais, laboratórios, etc. É fundamental que a(s) geometria(s) seja(m) algo que corresponda(m) aos nossos espaços. Preferencialmente, a implementação deve ser realizada em ANSI C ou C++, mas vocês podem implementar em outras linguagens de programação caso desejarem;

O código deve conter (vide pesos):
- [x] (25%) Modelagem das geometrias (ambiente a ser reproduzido);
- [x] (20%) Funções para translação, rotação e escala implementadas com as matrizes necessárias para serem aplicadas no ambiente utilizando-se da glMultMatrix();
- [x] (15%) Funções para as projeções perspectiva e ortogonal implementadas com as matrizes necessárias para serem aplicadas no ambiente utilizando-se da glMultMatrix();
- [x] (15%) Aplicação do modelo de iluminação (Phong) e de tonalização (Gouraud) estudados (podem utilizar as rotinas disponíveis na OpenGL);
- [x] (15%) Implementar e aplicar em alguma parte do ambiente ao menos um dos algoritmos de rasterização (Digital Differential Analyzer - DDA ou Bresenham);
    - [x] Implementação DDA;
    - [x] Implementação Bresenham;
    - [x] Aplicação dos algoritmos;
- [x] (10%) Aplicação de um dos algoritmos de visibilidade estudados (podem utilizar as rotinas disponíveis na OpenGL).

## Issues:
- Atualmente, o algoritmo de Bresenham só funciona para delta y positivo e menor que delta x, é necessário modificar isso; `FIXED ✅` 
- Como lidar com o eixo z nos algoritmos de rasterização? `FIXED ✅`
- De que forma temos que aplicar esss algoritmos de rasterização? `NUMA PARTE DO NOSSO DESENHO`
- Talvez tenhamos que definir as normais das faces dos desenhos pra que o modelo de Gouraud seja aplicado corretamente, temos que pesquisar melhor sobre isso. `AS PRE DEFINIDAS JÁ TEM AS NORMAIS, SE DESENHAR A PARTIR DOS VÉRTICES TEM QUE DEFNIR.`
- Atualmente, o algoritmo de visibilidade usado é o z-buffer, mas existem outras possibilidades. `TUDO BEM`    
