pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                dir('sensor_interface') {
                    dir('build'){
                        sh 'cmake .. -DCMAKE_BUILD_TYPE=Debug'
                        sh 'make'
                    }
                }

            }
        }
        stage('Unit Test'){
            steps {
                sh './unit_tests/read_temperature_test'
            }
        }

    }
}