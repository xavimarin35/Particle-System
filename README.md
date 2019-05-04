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


## TODO's


## How does it look this particle system?


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
