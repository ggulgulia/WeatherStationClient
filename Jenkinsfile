pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                sh 'cd sensor_interface'
                sh 'mkdir -p build && cd build'
                sh 'cmake .. -DCMAKE_BUILD_TYPE=Debug'
                sh 'make'
            }
        }

    }
}