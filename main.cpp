#include "AVLTree.hpp"
#include "BinarySearchTree.hpp"
#include "Cat.hpp"
#include "SplayTree.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <sstream>
#include <vector>

/* stuff from project 1 */
std::vector<Cat> project1() {
  std::ifstream cat_file("data/cats_dataset.csv");
  std::stringstream cat_data;
  cat_data << cat_file.rdbuf();

  char *pdata = (char *)cat_data.str().data();

  std::vector<Cat> cats;

  while (*pdata++ != '\n')
    ;

  while (*pdata != '\0') {
    uint32_t i = atoi(pdata);

    while (*pdata++ != ',')
      ;

    char *pbreed = pdata;

    while (*pdata++ != ',')
      ;
    pdata[-1] = '\0';

    uint32_t age = atoi(pdata);

    while (*pdata++ != ',')
      ;

    uint32_t weight = atoi(pdata);

    while (*pdata++ != ',')
      ;

    uint32_t idx_color = pdata - pbreed;

    while (*pdata++ != ',')
      ;
    pdata[-1] = '\0';

    uint32_t idx_gender = pdata - pbreed;

    while (*pdata++ != '\n')
      ;
    pdata[-1] = '\0';

    cats.emplace_back(Cat(i, pbreed, age, weight, idx_color, idx_gender));
  }

  std::cerr << "brooooooo\n";
  return cats;
}

int main() {
  /* part 1 */
  BinarySearchTree<int> bst;
  SplayTree<int> splay;
  AVLTree<int> avl;

  for (int i = 1; i < 101; i++) {
    bst.add(i);
    splay.add(i);
    avl.add(i);
  }

  std::ofstream bst_int_depth("data/bst/int_depth.csv");
  std::ofstream avl_int_depth("data/avl/int_depth.csv");
  std::ofstream splay_int_depth("data/splay/int_depth.csv");
  for (int i = 1; i < 101; i++) {
    uint32_t depth = 0;
    bst.find(i, &depth);
    bst_int_depth << depth << '\n';
    depth = 0;

    avl.find(i, &depth);
    avl_int_depth << depth << '\n';
    depth = 0;

    splay.find(i, &depth);
    splay_int_depth << depth << '\n';
  }
  bst_int_depth.close();
  avl_int_depth.close();
  splay_int_depth.close();

  uint32_t d = 0;
  std::cout << bst.find(0, &d) << ", " << d << '\n';
  d = 0;
  std::cout << bst.find(101, &d) << ", " << d << '\n';
  d = 0;
  std::cout << bst.find(102, &d) << ", " << d << '\n';

  /* part 2 */
  BinarySearchTree<int> bst1;
  SplayTree<int> splay1;
  AVLTree<int> avl1;

  std::vector<int> rand(100);
  std::iota(rand.begin(), rand.end(), 1);
  std::shuffle(rand.begin(), rand.end(), std::default_random_engine());

  for (int i : rand) {
    bst.add(i);
    splay.add(i);
    avl.add(i);
  }

  std::ofstream bst_rand_int_depth("data/bst/rand_int_depth.csv");
  std::ofstream avl_rand_int_depth("data/avl/rand_int_depth.csv");
  std::ofstream splay_rand_int_depth("data/splay/rand_int_depth.csv");
  for (int i = 1; i < 101; i++) {
    uint32_t depth = 0;
    bst.find(i, &depth);
    bst_rand_int_depth << depth << '\n';
    depth = 0;

    avl.find(i, &depth);
    avl_rand_int_depth << depth << '\n';
    depth = 0;

    splay.find(i, &depth);
    splay_rand_int_depth << depth << '\n';
  }
  bst_rand_int_depth.close();
  avl_rand_int_depth.close();
  splay_rand_int_depth.close();

  /* part 3 */
  BinarySearchTree<Cat> cat_bst;
  SplayTree<Cat> cat_splay;
  AVLTree<Cat> cat_avl;

  std::vector<Cat> cats = project1();

  for (Cat c : cats) {
    cat_bst.add(c);
    cat_avl.add(c);
    cat_splay.add(c);
  }

  std::ofstream cat_bst_depth("data/bst/cat_depth.csv");
  std::ofstream cat_avl_depth("data/avl/cat_depth.csv");
  std::ofstream cat_splay_depth("data/splay/cat_depth.csv");
  for (Cat c : cats) {
    uint32_t depth = 0;
    cat_bst.find(c, &depth);
    cat_bst_depth << depth << '\n';
    depth = 0;

    cat_avl.find(c, &depth);
    cat_avl_depth << depth << '\n';
    depth = 0;

    cat_splay.find(c, &depth);
    cat_splay_depth << depth << '\n';
  }
  cat_bst_depth.close();
  cat_splay_depth.close();
  cat_avl_depth.close();

  /* part 4 */
  SplayTree<Cat> cat_splay2;
  std::ofstream cat_splay_depth2("data/splay/cat_depth2.csv");
  for (Cat c : cats)
    cat_splay2.add(c);

  for (Cat c : cats) {
    uint32_t depth = 0;
    cat_splay2.find(c, &depth);
    cat_splay_depth2 << depth << '\n';
    depth = 0;

    cat_splay2.find(c, &depth);
    cat_splay_depth2 << depth << '\n';
    depth = 0;

    cat_splay2.find(c, &depth);
    cat_splay_depth2 << depth << '\n';
    depth = 0;

    cat_splay2.find(c, &depth);
    cat_splay_depth2 << depth << '\n';
    depth = 0;

    cat_splay2.find(c, &depth);
    cat_splay_depth2 << depth << '\n';
  }

  return 0;
}
