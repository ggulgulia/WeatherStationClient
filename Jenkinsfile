pipeline {
    agent any
    triggers{ cron('H/15 * * * *') }
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
                dir('sensor_interface') {
                    dir('build'){
                        sh './unit_tests/read_temperature_test'
                    }
                }
            }
            steps {
                dir('sensor_interface') {
                    dir('build'){
                        sh 'rm -rf *'
                        sh 'cmake .. -DCMAKE_BUILD_TYPE=Debug -DCOVERAGE=ON'
                        sh 'make'
                        sh 'make coverage'
                    }
                }
            }

        }
    }

    post {
        always {
            junit 'sensor_interface/build/coverage/index.html'
        }
    }
}