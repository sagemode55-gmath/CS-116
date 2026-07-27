#include <iostream>
#include <cstdint>
#include <iomanip>

// Structure to hold calculation results
struct ImageSizeInfo {
    uint64_t totalBits;
    uint64_t totalBytes;
    double totalMegaBytes;
};

// Function to calculate image storage details
ImageSizeInfo calculatePixelBits(uint32_t width, uint32_t height, uint32_t bpp) {
    ImageSizeInfo info;
    
    // Using uint64_t prevents integer overflow for large resolutions
    info.totalBits = static_cast<uint64_t>(width) * height * bpp;
    
    // Convert bits to bytes (division truncates any fractional bits remaining)
    info.totalBytes = info.totalBits / 8;
    
    // Convert bytes to Megabytes (1 MB = 1024 * 1024 bytes)
    info.totalMegaBytes = static_cast<double>(info.totalBytes) / (1024.0 * 1024.0);
    
    return info;
}

int main() {
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t bpp = 0;

    std::cout << "--- Pixel Bit Calculator ---" << std::endl;
    
    std::cout << "Enter image width (pixels): ";
    if (!(std::cin >> width)) return 1;

    std::cout << "Enter image height (pixels): ";
    if (!(std::cin >> height)) return 1;

    std::cout << "Enter bits per pixel (e.g., 8, 16, 24, 32): ";
    if (!(std::cin >> bpp)) return 1;

    // Run computation
    ImageSizeInfo result = calculatePixelBits(width, height, bpp);

    // Display Results
    std::cout << "\n--- Calculation Results ---" << std::endl;
    std::cout << "Total Pixels    : " << (static_cast<uint64_t>(width) * height) << " pixels" << std::endl;
    std::cout << "Total Data Size : " << result.totalBits << " bits" << std::endl;
    std::cout << "Total Data Size : " << result.totalBytes << " bytes" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total Data Size : " << result.totalMegaBytes << " MB (Binary / Mebibytes)" << std::endl;

    return 0;
}
