#include "checker.h"

static void	create_bar(char *buf, int len)
{
	*buf = '\0';
	while (len)
	{
		strncat(buf, ".", 1);
		len--;
	}
}

static t_rgb	pick_color(int region, int x)
{
	t_rgb	rgb;

	if (region == 0)
	{
		rgb.r = 255;
		rgb.g = x;
		rgb.b = 0;
	}
	if (region == 1)
	{
		rgb.r = 255 - x;
		rgb.g = 255;
		rgb.b = 0;
	}
	if (region == 2 || region == 3)
	{
		rgb.r = 0;
		rgb.g = 255;
		rgb.b = x;
	}
	return (rgb);
}

static t_rgb	get_rgb_color(t_element *el, int max)
{
	float	ratio;
	int		normalized;
	int		x;

	ratio = (float)el->value / max;
	normalized = (int)(ratio * 256 * 3);
	x = normalized % 256;
	return (pick_color((int)(normalized / 256), x));
}

static void	draw_bar(char *_v, t_element *stack, int max, int padding)
{
	t_rgb	rgb;

	create_bar(_v, stack->n_val + 1);
	printf("%5d: ", stack->value);
	rgb = get_rgb_color(stack, max);
	printf("\x1b[38;2;%d;%d;%dm", rgb.r, rgb.g, rgb.b);
	if (padding)
		printf("%-*s" "\x1b[0m", max + padding, _v);
	else
		printf("%s\n" "\x1b[0m", _v);
}

void	visualize_frame(t_element *a, t_element *b, int max)
{
	char	a_v[1000];
	char	b_v[1000];

	printf("\033[H\033[J");
	printf("%-*s", max + 15, "[STACK A]");
	printf("%s\n\n", "[STACK B]");
	while (a || b)
	{
		if (a)
		{
			draw_bar(a_v, a, max, 10);
			a = a->next;
		}
		else
			printf("%-*c", max + 17, ' ');
		if (b)
		{
			draw_bar(b_v, b, max, 0);
			b = b->next;
		}
		else
			printf("\n");
	}
}
