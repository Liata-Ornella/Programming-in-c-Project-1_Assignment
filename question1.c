#include <stdio.h>
#include <math.h>

// Calculates the water-quality index
float calculateIndex(float temperature, float turbidity)
{
    float temperatureDeviation = fabs(temperature - 25.0);
    float turbidityPenalty = turbidity / 2.0;

    return 100.0 - (temperatureDeviation + turbidityPenalty);
}

// Classifies the water quality
const char* classifyWater(float index)
{
    if (index >= 80.0)
    {
        return "Good";
    }
    else if (index >= 60.0)
    {
        return "Warning";
    }
    else
    {
        return "Critical";
    }
}

int main()
{
    float temperature;
    float turbidity;
    float index;

    printf("Enter temperature (C): ");
    scanf("%f", &temperature);

    printf("Enter turbidity (NTU): ");
    scanf("%f", &turbidity);

    index = calculateIndex(temperature, turbidity);

    printf("\n===== WATER QUALITY MONITORING REPORT =====\n");
    printf("Temperature: %.2f C\n", temperature);
    printf("Turbidity: %.2f NTU\n", turbidity);
    printf("Water Quality Index: %.2f\n", index);
    printf("Water Quality Status: %s\n", classifyWater(index));
    printf("===========================================\n");

    return 0;
}