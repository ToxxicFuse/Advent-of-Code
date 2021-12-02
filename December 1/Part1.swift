//
// Advent of Code 2021
// December 1 - Sonar Sweep
//
// Part2.swift
//
//  Created by Simon on 2021-12-02.
//

import Foundation

var depthMeasurements: Array<Int> = Array()
do{
    let fileContent = try String(contentsOfFile: "depthMeasurements.txt").split(separator: "\n")
    
    for line in fileContent{
        depthMeasurements.append(Int(line)!)
    }
}catch{
    print(error)
}

var counter = 0
for i in 1..<depthMeasurements.count{
    if(depthMeasurements[i] > depthMeasurements[i-1]){
        counter += 1
    }
}

print("There are \(counter) measurements that are larger than the previous measurement.")
