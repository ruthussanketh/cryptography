#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Public_Weights {
public:
  int weight;
};

class Plaintext {
public:
  int plaintext;
};

int MerkleHellmanEncrypt(vector<Public_Weights>PublicWeights, vector<Plaintext>xPlaintext)
{
  int ciphertext=0;
  unsigned size = PublicWeights.size();
  for (unsigned i=0;i<size;i++) {
    ciphertext += PublicWeights[i].weight*xPlaintext[i].plaintext;
  }
  return ciphertext;
}

int main()
{
  int n, a, b, C;
  cout<<"Enter the number of weights - ";
  cin>>n;

  std::vector<Public_Weights>public_weights_vector (n);
  std::vector<Plaintext>plaintext_vector (n);

  for (unsigned i=0; i<public_weights_vector.size(); i++)
  {
    cout<<"Weight "<<i+1<<" - ";
    cin>>a;
    public_weights_vector[i].weight=a;
  }

  while(1)
  {
      cout<<"\nEnter the binary plaintext sequence - ";
      cin>>b;
      for (unsigned i = 0; i<plaintext_vector.size(); i++)
      {
          int digit = b%10;
          b /= 10;
          if (digit!=1 && digit!=0)
          {
              cout<<"\nPlaintext must be a binary integer.";
              exit(0);
          }
          else
          {
              plaintext_vector[plaintext_vector.size()-1-i].plaintext = digit;
          }
      }
      C = MerkleHellmanEncrypt(public_weights_vector, plaintext_vector);
      cout<<"\nThe ciphertext is - "<<C<<"\n";
  }
}
