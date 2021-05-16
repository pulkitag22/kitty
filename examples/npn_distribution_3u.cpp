#include <iostream>
#include <unordered_set>

#include <kitty/kitty.hpp>

#define NUM_VARS 4u

int main()
{
  std::unordered_set<kitty::dynamic_truth_table, kitty::hash<kitty::dynamic_truth_table>>::iterator itr;

  auto class_sd = kitty::calculate_sd_represtative_class( NUM_VARS );
  auto class_npn = kitty::calculate_npn_represtative_class( NUM_VARS );
  uint16_t size_sd = class_sd.size();
  uint16_t size_npn = class_npn.size();
	
	kitty::dynamic_truth_table array_npn[size_npn];
  kitty::dynamic_truth_table array_sd[size_sd];
  
	itr = class_npn.begin();
  uint16_t i = 0;
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

  i = 0;
	int temp=0;
	int rain_check = 0;
  for ( i = 0; i < size_sd; i++ )
  {
		std::cout<<i<< " " ;
		kitty::print_binary(array_sd[i]);
		std::cout<<std::endl;
		temp = 0;
		
		for (int j=0; j<size_npn; j++){
						if (kitty::equal(array_sd[i], kitty::exact_sd_canonization(array_npn[j]))){
										std::cout<<temp+1<<" ";
										kitty::print_binary(array_npn[j]);
										std::cout<<std::endl;
										temp++;
										rain_check++;
						}
						continue;
		}
  }

	std::cout<<rain_check<< " ";

  return 0;
}
