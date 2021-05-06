#include <iostream>
#include <unordered_set>

#include <kitty/kitty.hpp>

int main()
{
  std::unordered_set<kitty::dynamic_truth_table, kitty::hash<kitty::dynamic_truth_table>>::iterator itr;

  auto class_sd = kitty::calculate_sd_represtative_class( 4u );
  auto class_npn = kitty::calculate_npn_represtative_class( 4u );
  kitty::dynamic_truth_table array_npn[222];
  kitty::dynamic_truth_table array_sd[83];
  return 0;
}
