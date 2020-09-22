pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                sh 'pwd'
                sh 'ls'
                dir('sensor_interface') {
                    sh 'pwd'
                    sh 'ls'
                    dir('build'){
                        sh 'cmake .. -DCMAKE_BUILD_TYPE=Debug'
                        sh 'make'
                        sh 'ls'
                    }
                }

            }
        }

    }
}