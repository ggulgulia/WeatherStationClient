pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                cd sensor_interface
		mkdir -p build && cd build
		cmake .. -DCMAKE_BUILD_TYPE=Debug
		make
		./unit_tests/read_temperature_test
            }
        }


    }
}


