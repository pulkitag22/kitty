#include <iostream>
#include <unordered_set>

#include <kitty/kitty.hpp>

int main()
{
  std::unordered_set<kitty::dynamic_truth_table, kitty::hash<kitty::dynamic_truth_table>>::iterator itr;

  auto class_sd = kitty::calculate_sd_represtative_class( 3u );
  auto class_npn = kitty::calculate_npn_represtative_class( 3u );
  kitty::dynamic_truth_table array_npn[14];
  kitty::dynamic_truth_table array_sd[7];

  itr = class_npn.begin();
  int i = 0;
  for ( itr = class_npn.begin(); itr != class_npn.end(); itr++ )
  {
    array_npn[i] = *itr;
    i++;
  }

  itr = class_sd.begin();
  i = 0;
  for ( itr = class_sd.begin(); itr != class_sd.end(); itr++ )
  {
    array_sd[i] = *itr;
    i++;
  }

  int distribution[7];
  int j = 0;
  i = 0;
  for ( i = 0; i < 7; i++ )
  {
    distribution[i] = 0;
  }
  i = 0;
  for ( i = 0; i < 14; i++ )
  {
    auto temp = kitty::exact_sd_canonization( array_npn[i] );
    for ( j = 0; j < 14; j++ )
    {
      if ( kitty::equal( temp, array_sd[j] ) )
      {
        distribution[j] += 1;
        break;
      }
    }
  }

  i = 0;
  for ( i = 0; i < 7; i++ )
  {
    kitty::print_binary( array_sd[i] );
    std::cout << "  " << distribution[i] << std::endl;
  }
  return 0;
}
