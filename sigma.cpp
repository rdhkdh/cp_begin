#include<bits/stdc++.h>
using namespace std;
 
// Function to calculate the total sum
string sumOfLargeNumbers(string v[], int k, int N)
{
    // Stores the array of large
    // numbers in integer format
    vector<vector<int> > x(1000);
 
    for (int i = 0; i < k; i++) {
 
        for (int j = 0; j < N; j++) {
 
            // Convert each element
            // from character to integer
            x[i].push_back(v[i][j] - '0');
        }
    }
 
    // Stores the carry
    int carry = 0;
 
    // Stores the result
    // of summation
    vector<int> result;
 
    for (int i = N - 1; i >= 0; i--) {
 
        // Initialize the sum
        int sum = 0;
 
        for (int j = 0; j < k; j++)
 
            // Calculate sum
            sum += x[j][i];
 
        // Update the sum by adding
        // existing carry
        sum += carry;
        int temp = sum;
 
        // Store the number of digits
        int count = 0;
        while (temp > 9) {
            temp = temp % 10;
 
            // Increase count of digits
            count++;
        }
 
        long long int l = pow(10, count);
        if (l != 1)
 
            // If the number exceeds 9,
            // Store the unit digit in carry
            carry = (double)sum / l;
 
        // Store the rest of the sum
        sum = sum % 10;
 
        // Append digit by digit
        // into result array
        result.push_back(sum);
    }
    while (carry != 0) {
        int a = carry % 10;
 
        // Append result until
        // carry is 0
        result.push_back(a);
        carry = carry / 10;
    }

    reverse(result.begin(),result.end());
    string res= "";
    for(auto u: result)
    {
        res += to_string(u);
    }

    return res;
}

// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);
 
    // Below two indexes are used to find positions
    // in result. 
    int i_n1 = 0; 
    int i_n2 = 0; 
     
    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0; 
         
        // Go from right to left in num2             
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";
 
    // generate the result string
    string s = "";
     
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}

// A function to perform division of large numbers
string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;
 
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (idx<(number.size()-1)&&temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
 
    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while ((number.size()-1 )> idx) {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
 
        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
 
    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";
 
    // else return ans
    return ans;
}

// Returns true if str1 is smaller than str2. 
bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 < n1) 
        return false; 
  
    for (int i = 0; i < n1; i++) 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
  
    return false; 
} 
  
// Function for find difference of larger numbers 
string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
  
    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i = 0; i < n2; i++) { 
        // Do school mathematics, compute difference of 
        // current digits 
  
        int sub 
            = ((str1[i] - '0') - (str2[i] - '0') - carry); 
  
        // If subtraction is less than zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (int i = n2; i < n1; i++) { 
        int sub = ((str1[i] - '0') - carry); 
  
        // if the sub value is -ve, then make it positive 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

int main()
{
    int n,K;
    cin>>n>>K;
    int a[n];
    set<string> s;
    for(int i=0;i<n;i++) {cin>>a[i];}

    for(int i=0;i<n;i++)
    {
        if(a[i]<=K) 
        {
            string str = to_string(a[i]);
            if(str.length()<10) //pad to 10 spaces
            {
                for(int i=1; i<=10-str.length()+1; i++)
                    str = '0'+str;
            }
            s.insert(str);
        }
    }

    int N = s.size();
    string v[N];
    int idx=0;
    for(auto u: s)
    {
        v[idx] = u;
        idx++;
    }

    string sum_a = sumOfLargeNumbers(v,N,10);
    cout<<"sum of array: "<<sum_a<<endl;

    string k_str = to_string(K);
    int Kplus = K+1;
    string kplus_str = to_string(Kplus);

    string k_str2;
    if(K%2==0) 
    {
        k_str2 = longDivision(k_str,2);
    }
    else{
        k_str2 = longDivision(kplus_str,2);
    }

    string sum_k = multiply(k_str,k_str2); // k*(k+1)/2
    cout<<"k*(k+1)/2: "<<sum_k<<endl;

    string ans = findDiff(sum_k,sum_a);

    cout<<"diff: "<<ans<<endl;
}