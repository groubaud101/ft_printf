#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = (*lst)->next;
	while (tmp)
	{
		ft_lstdelone(*lst, del);
		*lst = tmp;
		tmp = tmp->next;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}