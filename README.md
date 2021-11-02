<p align="center"><img src="https://user-images.githubusercontent.com/47906376/139920435-efc94d20-ab2e-43fc-bf03-c6f92c06efc3.png" width="315" height="224"></p>
<h1 align="center">Tiny Console</h1>
<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-brightgreen?logo=c%2B%2B">
  <img src="https://img.shields.io/badge/Version-v1.0-blue">
</p>

<h2>Contenido</h2>
<ol>
  <li><a href="#sobre"> ➤ Sobre la Librería</a></li>
  <li><a href="#instalacion"> ➤ ¿Como instalarlo?</a></li>
  <li><a href="#funcionamiento"> ➤ Funcionamiento</a></li>
  <li><a href="#ejemplo1"> ➤ Ejemplo 1</a></li>
  <li><a href="#ejemplo2"> ➤ Ejemplo 2</a></li>
  <li><a href="#ejemplo3"> ➤ Ejemplo 3</a></li>
  <li><a href="#sfml"> ➤ Ejemplo SFML</a></li>
  <li><a href="#detalles"> ➤ Detalles</a></li>
  <li><a href="#creditos"> ➤ Creditos</a></li>
</ol>
<p align="center"><img src="https://pngimage.net/wp-content/uploads/2018/05/blue-line-png.png"></p>
<h2 id="sobre">Sobre la Librería</h2>
<p>TinyConsole es una librería de fácil uso y dirigida a todo el publico (principiantes a expertos). Esta librería te da la capacidad de ejecutar cualquier función de tu código en tiempo de ejecución con tan solo escribir un comando!
  
Esto puede ser útil a la hora de hacer pruebas en tu programa en tiempo de ejecución, modificando variables y visualizando los cambios sin modificar el código. O simplemente puede ser usado como una forma en la que el usuario pueda interactuar con tu aplicación.</p>
<p align="center"><img src="https://pngimage.net/wp-content/uploads/2018/05/blue-line-png.png"></p>
<h2 id="instalacion">¿Como instalarlo?</h2>
<p>Es realmente sencillo implementar esta librería en cualquiera de tus proyectos. Simplemente descargue los 3 archivos (TinyConsole.cpp y .h y ArgConvert.h) y asegúrese que estos archivos estén en la misma carpeta que su archivo main.cpp!</p>
<p align="center"><img src="https://pngimage.net/wp-content/uploads/2018/05/blue-line-png.png"></p>
<h2 id="Funcionamiento">Funcionamiento</h2>
La librería permite llamar a cualquiera de tus funciones con solo escribir el comando con el que haya sido enlazado. La función debe de ser de tipo <b>void</b>, y puede aceptar cuantos parámetros desee (solo parámetros de tipo numérico y texto; char, int, float, string, etc…).

Para empezar a usar la librería, es necesario crear un objeto de la librería, <b>hd::TinyConsole cmd(‘/’)</b>. El constructor de esta clase solo lleva un parámetro, y es el carácter que se usara para llamar a todos los comandos que se hagan.

Para crear un comando, se utiliza la función <b>addCmd("ejem1", func1)</b>, el cual acepta 2 parámetros, el nombre de la función (de tipo std::string) y el puntero de la función a la que se enlazara (solo es necesario escribir el nombre de la función).

Con este paso completado, ya tendrías tu primer comando, el cual puede ser llamado con la función <b>run("/ejem1 123 456")</b>, lleva un solo parámetro, el cual es el string completo de todo tu comando.

<p align="center"><img src="https://pngimage.net/wp-content/uploads/2018/05/blue-line-png.png"></p>
<h2 id="ejemplo1">Ejemplo 1</h2>
<p align="center"><img src="https://pngimage.net/wp-content/uploads/2018/05/blue-line-png.png"></p>
<h2 id="ejemplo2">Ejemplo 2</h2>
<p align="center"><img src="https://pngimage.net/wp-content/uploads/2018/05/blue-line-png.png"></p>
<h2 id="ejemplo3">Ejemplo 3</h2>
<p align="center"><img src="https://pngimage.net/wp-content/uploads/2018/05/blue-line-png.png"></p>
<h2 id="sfml">Ejemplo SFML</h2>
<p align="center"><img src="https://pngimage.net/wp-content/uploads/2018/05/blue-line-png.png"></p>
<h2 id="detalles">Detalles</h2>
<p align="center"><img src="https://pngimage.net/wp-content/uploads/2018/05/blue-line-png.png"></p>
<h2 id="creditos">Creditos</h2>
