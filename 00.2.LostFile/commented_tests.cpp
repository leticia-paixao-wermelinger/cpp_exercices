#include <vector>               // Biblioteca para o uso do vetor dinâmico.
#include <algorithm>            // Biblioteca para funções de algoritmos, como std::for_each.
#include <functional>           // Biblioteca para funções como std::mem_fun_ref.
#include "Account.hpp"          // Cabeçalho que define a classe Account.

int main( void ) {

    // Alias para simplificar a sintaxe dos tipos usados no código.
    typedef std::vector<Account::t> accounts_t; // Vetor de contas do tipo definido em Account.
    typedef std::vector<int> ints_t;            // Vetor de inteiros.
    typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; // Par de iteradores: um para contas e outro para inteiros.

    // Array de saldos iniciais.
    int const amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };
    size_t const amounts_size( sizeof(amounts) / sizeof(int) ); // Calcula o número de elementos no array.
    accounts_t accounts( amounts, amounts + amounts_size );     // Inicializa o vetor de contas com os valores do array.
    accounts_t::iterator acc_begin = accounts.begin();          // Iterador para o início do vetor de contas.
    accounts_t::iterator acc_end = accounts.end();              // Iterador para o final do vetor de contas.

    // Array de valores de depósito.
    int const d[] = { 5, 765, 564, 2, 87, 23, 9, 20 };
    size_t const d_size( sizeof(d) / sizeof(int) );             // Calcula o número de elementos no array.
    ints_t deposits( d, d + d_size );                           // Inicializa o vetor de depósitos.
    ints_t::iterator dep_begin = deposits.begin();              // Iterador para o início do vetor de depósitos.
    ints_t::iterator dep_end = deposits.end();                  // Iterador para o final do vetor de depósitos.

    // Array de valores de saque.
    int const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
    size_t const w_size( sizeof(w) / sizeof(int) );             // Calcula o número de elementos no array.
    ints_t withdrawals( w, w + w_size );                        // Inicializa o vetor de saques.
    ints_t::iterator wit_begin = withdrawals.begin();           // Iterador para o início do vetor de saques.
    ints_t::iterator wit_end = withdrawals.end();               // Iterador para o final do vetor de saques.

    // Exibe informações gerais sobre as contas.
    Account::displayAccountsInfos();

    // Aplica a função displayStatus para cada conta no vetor usando std::for_each.
    std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

    // Realiza os depósitos.
    for ( acc_int_t it( acc_begin, dep_begin );                 // Par de iteradores inicializados.
          it.first != acc_end && it.second != dep_end;           // Continua enquanto não atinge o final das contas ou depósitos.
          ++(it.first), ++(it.second) ) {                        // Incrementa ambos os iteradores.

        (*(it.first)).makeDeposit( *(it.second) );              // Faz o depósito na conta.
    }

    // Exibe novamente as informações das contas após os depósitos.
    Account::displayAccountsInfos();
    std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

    // Realiza os saques.
    for ( acc_int_t it( acc_begin, wit_begin );                  // Par de iteradores inicializados.
          it.first != acc_end && it.second != wit_end;           // Continua enquanto não atinge o final das contas ou saques.
          ++(it.first), ++(it.second) ) {                        // Incrementa ambos os iteradores.

        (*(it.first)).makeWithdrawal( *(it.second) );           // Faz o saque na conta.
    }

    // Exibe as informações das contas após os saques.
    Account::displayAccountsInfos();
    std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

    return 0;
}