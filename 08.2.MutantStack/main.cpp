/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:32:48 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/06 19:32:50 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <typeinfo>

// subject main
int	main()
{
    MutantStack<int>
    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "size(mstack) = " << mstack.size() << std::endl;
    std::cout << "size(s)      = " << s.size() << std::endl;
    mstack.pop();
    std::cout << "Depois de pop() em mstack:" << std::endl;
    std::cout << "size(mstack) = " << mstack.size() << std::endl;
    std::cout << "size(s)      = " << s.size() << std::endl;
    std::cout << "mstack type = " << typeid(mstack).name() << std::endl;
    std::cout << "s type      = " << typeid(s).name() << std::endl;
    return 0;
}
/*
// subject main with list
int	main()
{
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << lstack.back() << std::endl;
    lstack.pop_back();
    std::cout << lstack.size() << std::endl;
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    //[...]
    lstack.push_back(0);
    std::list<int>::iterator it = lstack.begin();
    std::list<int>::iterator ite = lstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    //std::deque<int> deque_stack(lstack.begin(), lstack.end());
    //std::stack<int> s(deque_stack);
    return 0;
}*/