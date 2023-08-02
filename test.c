
#include "header.h"

void	read_dir(DIR *dir)
{
	struct dirent *reading;

	while ((reading = readdir(dir)))
			printf("name = %s\n", reading->d_name);
}

void	print_path()
{
	char	*path;

	path = getcwd(NULL, 0);
	printf("path = %s]\n",path);
}

void	get_env(char *var)
{
	char *env_var;

	env_var = getenv(var);
	printf("env = %s\n", env_var);
}

void	func()
{
	char *str;
	while (1)
	{
		str = readline("> ");

	}
}

int main(int ac, char **av)
{
    char *input;
	char *path;

    while (1)
	{
		input = readline("Minishell$ ");

		func();
		// add_history(input);
		// DIR *directory = opendir("dir");
		// read_dir(directory);
		// print_path();
		// get_env(av[1]);
		// // chdir("/Users/zouaraqa/Desktop/the_shell/dir");

		
		// if (input != NULL)
		// 	free(input);
		// closedir(directory);
    }

	
    return 0;
}