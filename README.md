## Alice :desktop_computer:
Por: João Vitor da Rosa Ignacio
   Bruno Leite

  O programa roda dentro de uma classe principal chamada menu, a classe se procupa em mostrar ao usuário os
resultados das opções na tela e também de receber comandos.

## Funcionalidades :floppy_disk:

A classe `Menu` permite:
- Adicionar páginas ao histórico.
- Remover páginas do histórico.
- Navegar pelas páginas visitadas (anterior/próximo).
- Gerenciar uma lista de favoritos (adicionar, remover, navegar e imprimir).

## Descrição das Funções :gear:

### 1. `Menu::invoke(page* aux)`
- **Descrição:** Recebe uma struct e se refere ao nome do site na hora de apresentar o menu ao usuário.
- **Parâmetros:** Recebe um ponteiro para a estrutura da página atual.
- **Custo:** Linear, dependendo da navegação necessária para chegar ao site.

### 2. `Menu::newPage(page* aux)`
- **Descrição:** Recebe o site atual e caminha até final do histórico para adicionar uma nova página no fim desta lista. 
- **Parâmetros:** Recebe um ponteiro para a estrutura da página atual.
- **Custo:** Linear, proporcional ao tamanho do histórico.

### 3. `Menu::removePage(page* aux)`
- **Descrição:** Recebe o site atual e exclui ele do histórico se não for o site raíz. 
- **Parâmetros:** Recebe um ponteiro para a estrutura da página atual.
- **Custo:** Linear, proporcional ao tamanho do histórico.

### 4. `Menu::lastPage(page* aux)`
- **Descrição:** Recebe o site atual, verifica se existe algum site anterior e retorna este site se possível. 
- **Parâmetros:** Recebe um ponteiro para a estrutura da página atual.
- **Custo:** Linear, proporcional ao tamanho do histórico.

### 5. `Menu::nextPage(page* aux)`
- **Descrição:** Retorna a próxima página no histórico, se existir.
- **Parâmetros:** Recebe um ponteiro para a estrutura da página atual.
- **Custo:** Linear, proporcional ao tamanho do histórico.

### 6. `Menu::printHistory(page* aux)`
- **Descrição:** Imprime todas as páginas do histórico.
- **Parâmetros:** Recebe um ponteiro para a estrutura da página atual.
- **Custo:** Linear, proporcional ao tamanho do histórico.

### 7. `Menu::addFavorite(page* aux, page* ret, page* froot)`
- **Descrição:** Adiciona a página atual à lista de favoritos, se ela ainda não for um favorito e não for a página raiz.
- **Parâmetros:** 
  - `aux`: Página atual.
  - `ret`: Página anterior no histórico.
  - `froot`: Raiz da lista de favoritos.
- **Custo:** Linear, proporcional ao tamanho da lista de favoritos.

### 8. `Menu::nextFavorite(page* aux, page* ret, page* root, page* froot)`
- **Descrição:** Navega para o próximo favorito a partir da página atual.
- **Parâmetros:**
  - `aux`: Página atual.
  - `ret`: Página anterior no histórico.
  - `root`: Raiz do histórico.
  - `froot`: Raiz dos favoritos.
- **Custo:** Linear, mas dobrado devido à necessidade de percorrer duas listas.

### 9. `Menu::removeFavorite(page* aux, page* ret, page* root, page* froot)`
- **Descrição:** Remove a página atual da lista de favoritos, mantendo-a no histórico principal.
- **Parâmetros:**
  - `aux`: Página atual.
  - `ret`: Página anterior no histórico.
  - `root`: Raiz do histórico.
  - `froot`: Raiz dos favoritos.
- **Custo:** Semelhante à função anterior, linear com dobro de esforço.

### 10. `Menu::printFavorite(page* aux, page* ret)`
- **Descrição:** Imprime todas as páginas da lista de favoritos.
- **Parâmetros:** 
  - `aux`: Página atual.
  - `ret`: Página referente do histórico de favoritos.
- **Custo:** Linear, proporcional ao tamanho da lista de favoritos.

## Estrutura de Dados :computer: 

As operações são realizadas utilizando listas duplamente encadeadas para o histórico e a lista de favoritos, garantindo uma navegação eficiente.

## Complexidade :printer: 

A maioria das funções tem custo **linear** devido à necessidade de percorrer as listas. A performance pode variar dependendo do tamanho do histórico e da lista de favoritos.

## Como Usar :book: 

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu_usuario/menu-class.git
