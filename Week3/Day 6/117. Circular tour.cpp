class Solution{
  public:
    int tour(petrolPump p[],int n)
    {
        // shuru mein start aur end dono 0 honge
        int start = 0;
        int end = 1;
        
        // current_petrol mein pehle petrol pump ka petrol daal do
        int current_petrol = p[start].petrol - p[start].distance;
        
        // jab tak start end ke barabar nahi ho jaata, tab tak loop chalao
        while(end != start || current_petrol < 0)
        {
            // jab tak current_petrol negative hai aur start end ke barabar nahi ho jaata
            // tab tak start ko aage badhao aur uska petrol current_petrol se minus karo
            while(current_petrol < 0 && start != end)
            {
                // pehle petrol pump ka petrol current_petrol se minus karo
                current_petrol -= p[start].petrol - p[start].distance;
                
                // agar start end ke barabar ho gaya toh start ko 0 kar do
                start = (start + 1) % n;
                
                // agar start 0 ho gaya toh return -1 karo kyunki solution possible nahi hai
                if(start == 0)
                    return -1;
            }
            
            // next petrol pump ka petrol current_petrol mein add karo
            current_petrol += p[end].petrol - p[end].distance;
            
            // end ko aage badhao
            end = (end + 1) % n;
        }
        
        // agar loop se bahar aa gaye toh start return karo kyunki wohi solution hai
        return start;
    }
};
