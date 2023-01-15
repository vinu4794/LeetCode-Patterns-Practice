#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> FlipImage(vector<vector<int>> image)
{
    
    // Mirror
    for (int i = 0; i < image.size(); i++) {
        int l = 0;
        int r = image[i].size() - 1;

        while (l < r) {
            int temp = image[i][l];
            image[i][l] = image[i][r];
            image[i][r] = temp;

            // Invert
            image[i][l] = image[i][l] ^ 1;
            image[i][r] = image[i][r] ^ 1;

            l++;
            r--;
        }
        image[i][l] = image[i][l] ^ 1;
    }
    return image;

}

int main() {
 std::vector<std::vector<std::vector<int>>> images = {
        {{1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}}
    };
  for (int i = 0; i < images.size();i++){
		std::vector<std::vector<int>> result = FlipImage(images[i]);
        // std::cout << "\tFlipped and inverted image: " << Print2DList(result) << std::endl;
		// std::cout<<std::string(100,'-')<<std::endl;
  } 
}