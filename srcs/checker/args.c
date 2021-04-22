#include "checker.h"

static short	string_is_num(char *str)
{
	if (*str != '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static void	usage(void)
{
	printf("usage: ./checker [-v:<frame_delay>] [-p:<frame_delay>] [-c]\n\n");
	printf("Check push_swap output:\n");
	printf("-v: visualize operations.\n");
	printf("-p: print stacks after exexuting instructions\n");
	printf("-c: print number of push_swap instruction\n\n");
	printf("NOTE: [-v] and [-p] cannot coexist\n\n");
	exit(1);
}

static void	get_frame_delay(char *argv, t_op *options)
{
	while (*argv && *argv != ':')
		argv++;
	argv++;
	if (!string_is_num(argv))
		error();
	options->frame_delay = simple_atoi(argv);
}

static void	extract_option(char *argv, t_op *options)
{
	if (ft_strncmp(argv, "-h", 3) == 0)
		usage();
	else if (ft_strncmp(argv, "-v:", 3) == 0)
	{
		if (options->visualize || options->frame_delay)
			error();
		get_frame_delay(argv, options);
		options->visualize = 1;
	}
	else if (ft_strncmp(argv, "-p:", 3) == 0)
	{
		if (options->print || options->frame_delay)
			error();
		get_frame_delay(argv, options);
		options->print = 1;
	}
	else if (ft_strncmp(argv, "-c", 3) == 0)
	{
		if (options->count)
			error();
		options->count = 1;
	}
	else
		error();
}

short	read_options(char **argv, t_op *options)
{
	short	i;

	i = 0;
	while (argv[i] && !string_is_num(argv[i]))
	{
		extract_option(argv[i], options);
		i++;
	}
	return (i);
}
