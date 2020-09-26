pipeline {
    agent any
    triggers{ cron('H/5 * * * *') }
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
                sh 'pwd'
                dir('sensor_interface') {
                    sh 'pwd'
                    dir('build'){
                        sh 'pwd'
                        sh './unit_tests/read_temperature_test'
                    }
                }
            }
        }

    }
}