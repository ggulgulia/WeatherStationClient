pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                sh 'cd ${env.JOB_NAME}'
                sh 'cd sensor_interface'
                sh 'pwd'
            }
        }

    }
}