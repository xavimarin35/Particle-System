# 2D Particle System

I am [Xavi Marín Solà](https://www.linkedin.com/in/xavi-mar%C3%ADn-sol%C3%A0-82aaaa153/), student of the
[Bachelor’s Degree in Video Games by UPC at CITM](https://www.citm.upc.edu/ing/estudis/graus-videojocs/). 
This content is generated for the second year’s subject Project 2, under supervision of lecturer
[Ricard Pillosu](https://es.linkedin.com/in/ricardpillosu).

## About particle systems
### What are them?
A particle system is a collection of many many minute particles that together represent a fuzzy object. Over a period of time, particles are generated into a system, move and change from within the system, and die from the system.”

### Do we really use them?
Since the early 1980s, particle systems have been used in countless videogames, animations, digital art pieces, and installations to model various irregular types of natural phenomena, such as fire, smoke, waterfalls, fog, grass, bubbles, and so on.

Particle systems are important because they have a notorious visual impact that make the player experience better.
Here you can see some examples:

![Dragon Ball](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/ExcitableCloudyIslandwhistler-size_restricted.gif)

![Battlefield](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/giphy%20(1).gif)


## How is organized?
### Pool
The pool improves performance and memory use by reusing objects from a fixed pool instead of allocating and freeing them individually.

### Emitter
The emitter task is to create particles with the characteristics we define.

### Particle
Is simply a rendered sprite that when changing its properties simulates the effects we desire. 

These properties are:
- **startColor:** initial color of each particle (RGBA).
- **endColor:** final color of each particle (RGBA).
- **angle:** angle where particles go.
- **speed:** the speed of the particles.
- **particleLife:** how long the particle lives.
- **emitterLife:** how long the emitter lives.
- **texRect:** SDL_Texture attributes (x, y, w, h).
- **randomizer:** randomizes the emission of particles.
- **size:** size of each particle.
- **emission:** how many particles are emitted.

### ParticleManager
In general terms, is in charge of controlling everything of the system. 
- Does the Update, PostUpdate, CleanUp... of the emitters created.
- Loads all the data of the XML file
- Creates emitters.
- Destoys the emitters created.

## How is implemented?
The implementation of this particle system is based on this schema, so I'm going to explain the performance of the system starting from left to right.

![schema](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/schema.png)

### j1ParticleManager class
Manages the functionality of the emitters by loading their data and calling their modules through a list.

![modules](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/emitterlist.PNG)

It also spawns the emitters you desire

![spawn](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/spawnemitter.PNG)

And removes them too

![remove](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/removeemitters.PNG)

### j1Emitter class
Basically creates an new j1Pool on the constructor

![container](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/emittercontainer.PNG)

And in its Update() method, the container will keep on creating more and more particles with those random values

![updateemitter](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/emitterupdate.PNG)

### j1Pool class
To avoid memory fragmentation we use this class. In games, it's very important to have a good management of memory, that's why is not a good idea to allocate and free individually each particle. 

So, a pool class is the solution because we are able to reuse particles. To implement it we must declare an array of particles and the first particle of this mentioned array

![pooldeclaration](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/pooldeclaration.PNG)

When we have declared the array and the first particle, we must create them on the constructor

![pool](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/poolstart.PNG)

In the update we will check if the particle is alive or not. 

If it's alive, the Update() and Draw() methods of the j1Particle class are called. But if it's not alive, the first particle will become the first available of the array.

![poolupdate](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/poolupdate.PNG)

Finally, must exist a function to create particles with the properties we want

![poolcreate](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/poolcreate.PNG)


### j1Particle class
Every particle has some properties that we must change in order to obtain a particular behaviour. These are the properties:

![prop](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/particlestruct.PNG)

In order to create particles in the pool we need to ease the values of these particle properties, so that's why we need this function that will be called in the j1Pool class

![loadprop](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/propparticle.PNG)

## TODO's


## How does it look this particle system?

![gif](https://raw.githubusercontent.com/xavimarin35/Particle-System/gh-pages/Info/psXavi.gif)

## References
- https://gamedevelopment.tutsplus.com/tutorials/make-your-game-pop-with-particle-effects-and-quadtrees--gamedev-2138 
- http://buildnewgames.com/particle-systems/ 
- https://gamedevelopment.tutsplus.com/articles/mastering-the-gamemaker-studio-particle-system--cms-22782 
- https://learnopengl.com/In-Practice/2D-Game/Particles 
- https://www.3dgep.com/simulating-particle-effects-using-opengl/ 
- https://www.codeproject.com/Articles/10003/A-basic-Particles-System 
- https://natureofcode.com/book/chapter-4-particle-systems/ 
- http://gameprogrammingpatterns.com/object-pool.html 
- https://www.khanacademy.org/computing/computer-programming/programming-natural-simulations/programming-particle-systems/a/a-particle-system 
- https://stackoverflow.com/questions/13488957/interpolate-from-one-color-to-another
- http://gameprogrammingpatterns.com/object-pool.html
