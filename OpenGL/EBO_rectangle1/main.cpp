#include <OpenGL/gl3.h>
#include <SDL2/SDL.h>
#include <string>

#define WIDTH 500
#define HEIGHT 300

GLuint shaderProgram(std::string filename);

int				main()
{
	SDL_Window		*win;
	SDL_GLContext	context;
	bool			is_closed;
	SDL_Event		event;
	float vertices[] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.0f, 0.5f, 0.0f
	};
	unsigned int indices[] = {
		0,1,3,
		1,2,3
	};
	
	if(0 != SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Error: VIDEO MODE\n");
		exit(1);
	}
	if(!(win = SDL_CreateWindow("tretre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)))
	{
		fprintf(stderr, "Error: WINDOW\n");
		exit(1);
	}
	if(0 == (context = SDL_GL_CreateContext(win)))
	{
		fprintf(stderr, "Error: VIDEO MODE\n");
		exit(1);
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	is_closed = false;
	
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	unsigned int EBO;//ELEMENT BUFFER OBJECT
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);;



	GLuint program = shaderProgram("shader");
	glVertexAttribPointer(0, 3,  GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	while(!is_closed)
	{
		SDL_WaitEvent(&event);
		if(event.window.event == SDL_WINDOWEVENT_CLOSE)
			is_closed = true;
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(program);
		
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glUseProgram(0);
		SDL_GL_SwapWindow(win);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &VBO);

	glDisableVertexAttribArray(0);
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
